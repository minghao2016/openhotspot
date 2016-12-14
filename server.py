# BSD 3-Clause License
# Canalysis (Crime Analysis) 0.1.0
# Copyright (c) 2016, Matt Perez, all rights reserved.
#
# This source is licensed under the BSD 3-Clause License.
# The license can be found in the main directory for more
# information about using this program.
from __future__ import print_function

import os
import csv
import flask
import collections


class Server(object):
    def __init__(self, csvfile=None, port=None):
        self.csvfile = csvfile
        self.port = port
        # variance scale of 5 miles
        self.variance_scale = 5
        # variance crime rate of 10 crimes or more in a single variance
        self.variance_rate = 10
        # a max amount of variances of 40
        self.max_variances = 40

    def _parse_csvfile(self):
        column = collections.defaultdict(list)

        with open(self.csvfile, "r") as csvfile:
            reader = csv.DictReader(csvfile)
            for row in reader:
                for info, value in row.iteritems():
                    column[info].append(value)

        lat_column = column["lat"]
        long_column = column["long"]
        return lat_column, long_column

    def _variance(self):
        """
        Summary:
        """
        lat_column, long_column = self._parse_csvfile()

if __name__ == '__main__':
    server = Server(csvfile="prediction.csv",
                    port="0.0.0.0")
    server._variance()
