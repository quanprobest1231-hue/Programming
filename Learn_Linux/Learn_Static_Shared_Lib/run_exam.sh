#!/bin/bash

# Thêm thư mục chứa shared library vào LD_LIBRARY_PATH
export LD_LIBRARY_PATH=lib/shared:$LD_LIBRARY_PATH

# Chạy chương trình
./bin/exam_shared
