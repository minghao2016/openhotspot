from __future__ import print_function

import csv
import collections
import numpy as np
from flask import Flask, render_template

app = Flask(__name__)
csvfile = "../data/prediction.csv"

def _parse_csvfile():
    column = collections.defaultdict(list)
    with open(self.csvfile, "r") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            for info, value in row.iteritems():
                column[info].append(value)

@app.route('/')
def _plot_clusters():
    return render_template("base.html")

if __name__ == '__main__':
    app.run()
