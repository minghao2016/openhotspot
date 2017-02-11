#!/bin/sh
.././hotspot --reformat-file sf_dataset_1k.csv --crime-column 1 --days-column 3 \
--lat-column 10 --long-column 9

.././hotspot --crime-file ../data/crimes.txt --days-file ../data/c_days.txt --lat-file \
../data/c_latitudes.txt --long-file ../data/c_longitudes.txt --eps 0.5 --min-pts 1000 \
--distance-metric haversine

python ../scripts/server.py
