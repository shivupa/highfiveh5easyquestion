# highfive h5easy eigen question


```
mkdir build
cd build
cmake ..
make
./bin/test
h5dump example.h5
```

Example output:
```
HDF5 "example.h5" {
GROUP "/" {
   DATASET "col_vec" {
      DATATYPE  H5T_IEEE_F64LE
      DATASPACE  SIMPLE { ( 10 ) / ( 10 ) }
      DATA {
      (0): 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      }
   }
   DATASET "row_vec" {
      DATATYPE  H5T_IEEE_F64LE
      DATASPACE  SIMPLE { ( 10 ) / ( 10 ) }
      DATA {
      (0): 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      }
   }
}
}
```

