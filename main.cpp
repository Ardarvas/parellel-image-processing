#include <opencv2/opencv.hpp>
#include <omp.h>
#include <iostream>
#include <chrono>
#include <thread>

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file> <process_type>" << std::endl;
        std::cerr << "Process types: grayscale, blur, edge" << std::endl;
        return -1;
    }

    std::string input_file = argv[1];
    std::string output_file = argv[2];
    std::string process_type = argv[3];

    cv::Mat img = cv::imread(input_file, cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cerr << "Error: Could not load input file! Ensure the file exists and is a valid image." << std::endl;
        return -1;
    }

    cv::Mat output;

    // Perform processing based on the selected type
    auto start = std::chrono::high_resolution_clock::now();

    if (process_type == "grayscale") {
        output = cv::Mat(img.rows, img.cols, CV_8UC1);
        int thread_count = std::thread::hardware_concurrency(); // Dynamic thread count
        std::cout << "Using " << thread_count << " threads for grayscale processing." << std::endl;

        #pragma omp parallel for num_threads(thread_count)
        for (int i = 0; i < img.rows; ++i) {
            for (int j = 0; j < img.cols; ++j) {
                cv::Vec3b color = img.at<cv::Vec3b>(i, j);
                uchar gray = static_cast<uchar>(0.2989 * color[2] + 0.5870 * color[1] + 0.1140 * color[0]);
                output.at<uchar>(i, j) = gray;
            }
        }
    } else if (process_type == "blur") {
        cv::GaussianBlur(img, output, cv::Size(15, 15), 0);
    } else if (process_type == "edge") {
        cv::Mat gray;
        cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
        cv::Canny(gray, output, 100, 200);
    } else {
        std::cerr << "Error: Invalid process type! Available options are: grayscale, blur, edge" << std::endl;
        return -1;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    cv::imwrite(output_file, output);
    std::cout << "Processing completed in " << elapsed.count() << " seconds." << std::endl;
    std::cout << "Output saved to: " << output_file << std::endl;

    return 0;
}
