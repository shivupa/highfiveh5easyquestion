#include <Eigen/Eigen>
#include <highfive/H5Easy.hpp>

int main(int argc, char **argv) {

    Eigen::Matrix<double, 10, 1> col_vec = Eigen::Matrix<double, 10, 1>::Random();
    Eigen::Matrix<double, 1, 10> row_vec = Eigen::Matrix<double, 1, 10>::Random();

    H5Easy::File file("example.h5", H5Easy::File::Overwrite);

    H5Easy::dump(file, "col_vec_orig", col_vec);
    H5Easy::dump(file, "row_vec_orig", row_vec);

    file.createDataSet("row_vec", row_vec);
    file.createDataSet("col_vec", col_vec);

    return 0;
}
