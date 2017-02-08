from __future__ import print_function

import csv
import collections
import numpy as np
from flask import Flask, render_template

app = Flask(__name__)

def _parse_csvfile(csvfile):
    column = collections.defaultdict(list)
    with open(self.csvfile, "r") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            for info, value in row.iteritems():
                column[info].append(value)
    return {"core_lat":column["core_lat"],
            "core_long":column["core_long"],
            "noise_lat":column["noise_lat"],
            "noise_long":column["noise_long"]}

@app.route('/')
def _plot_clusters():
    parser = _parse_csvfile(csvfile="../data/prediction.csv")
    return render_template("base.html",
                            core_lat=float(parser["core_lat"]),
                            core_long=float(parser["core_long"]),
                            noise_lat=float(parser["noise_lat"]),
                            noise_long=float(parser["noise_long"]))

if __name__ == '__main__':
    app.run(port=8080)
