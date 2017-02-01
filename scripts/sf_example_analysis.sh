#!/bin/sh
.././hotspot --reformat-file sf_dataset_1k.csv --crime-column 1 \
--date-column 4 --lat-column 10 --long-column 9

.././hotspot --crime-file ../data/crimes.txt --dates-file \
../data/dates.txt --lat-file ../data/latitudes.txt --long-file \
../data/longitudes.txt --eps 1.7 --min-pts 1000 --distance-metric haversine

python ../launch/server.py
