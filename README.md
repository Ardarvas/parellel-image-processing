
# Parallel Image Processing

This project demonstrates a parallel image processing application in C++ using **OpenMP** for parallelism and **OpenCV** for image handling. The application allows users to apply different image processing techniques (grayscale, blur, and edge detection) with parallel processing.

## Features
- **Grayscale Processing**: Converts a color image to grayscale using OpenMP.
- **Blur**: Applies Gaussian blur to the input image.
- **Edge Detection**: Detects edges in the image using the Canny algorithm.
- **Dynamic Thread Management**: Automatically adjusts the number of threads based on available CPU cores.
- **Performance Measurement**: Displays processing time for each operation.

## Requirements
- **C++17** or higher
- **CMake** (3.10 or higher)
- **OpenCV** (4.x)
- **OpenMP**

## Installation and Usage

### 1. Clone the repository
 git clone https://github.com/ardarvas/parallel-image-processing.git
 cd parallel-image-processing


###  2. Build the project

mkdir build
cd build
cmake ..
make

### 3. Run the application

./ParallelImageProcessing <input_file> <output_file> <process_type>

## Example:

./ParallelImageProcessing image.jpg output.jpg grayscale


## Process Types
grayscale: Converts the image to grayscale.
blur: Applies Gaussian blur to the image.
edge: Detects edges in the image using the Canny algorithm.

## Performance
The application leverages parallelism to reduce processing time for large images. Thread count is dynamically adjusted based on available CPU cores.



