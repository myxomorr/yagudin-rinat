#!/bin/bash

srun -p banana -N5 cd worker/
srun -p banana -N5 make all
