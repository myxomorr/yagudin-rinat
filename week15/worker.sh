#!/bin/bash
#SBATCH --job-name=worker
#SBATCH --partition=banana
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --exclusive
#SBATCH --time=00:10:00
#SBATCH --array=0-4

srun ./worker/build/worker
