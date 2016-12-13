# BSD 3-Clause License
# Canalysis v0.0.1 Alpha
# Copyright (c) 2016, Matt Perez, all rights reserved.
#
# This source is licensed under the BSD 3-Clause License.
# The license can be found in the main directory for more
# information about using this program.
from __future__ import print_function

import os
import flask


class Server(object):
    def __init__(self):
        # variance scale of 5 miles
        self.variance_scale = 5
        # variance crime rate of 10 crimes or more in a single variance
        self.variance_rate = 10
        # a max amount of variances of 40
        self.max_variances = 40

    def variance(self):
        pass
