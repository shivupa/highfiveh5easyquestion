#include <Eigen/Eigen>
#include <highfive/H5Easy.hpp>

int main(int argc, char **argv) {

    Eigen::Matrix<double, Eigen::Dynamic, 1> col_vec;
    col_vec.resize(10);
    col_vec.Random();
    Eigen::Matrix<double, 1, Eigen::Dynamic> row_vec;
    row_vec.resize(10);
    row_vec.Random();

    H5Easy::File file("example.h5", H5Easy::File::Overwrite);
    H5Easy::dump(file, "/col_vec", col_vec);
    H5Easy::dump(file, "/row_vec", row_vec);

    return 0;
}
