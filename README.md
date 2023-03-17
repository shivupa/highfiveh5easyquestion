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
      (0): 0.680375, -0.211234, 0.566198, 0.59688, 0.823295, -0.604897,
      (6): -0.329554, 0.536459, -0.444451, 0.10794
      }
   }
   DATASET "row_vec" {
      DATATYPE  H5T_IEEE_F64LE
      DATASPACE  SIMPLE { ( 10 ) / ( 10 ) }
      DATA {
      (0): -0.0452059, 0.257742, -0.270431, 0.0268018, 0.904459, 0.83239,
      (6): 0.271423, 0.434594, -0.716795, 0.213938
      }
   }
}
}
```


