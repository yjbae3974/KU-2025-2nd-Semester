# matmul_base Profiling Data

## Summary

All profiling data has been extracted from gem5 simulations for matmul_base with three matrix sizes:
- (16, 512, 512)
- (16, 1024, 1024)  
- (16, 2048, 2048)

## Files Generated

1. **matmul_base_profiling_data.txt** - Detailed profiling data with all metrics
2. **matmul_base_profiling_summary.csv** - CSV format for easy analysis
3. **matmul_base_16_512_512/stats.txt** - Full stats for (16, 512, 512)
4. **matmul_base_16_1024_1024/stats.txt** - Full stats for (16, 1024, 1024)
5. **matmul_base_16_2048_2048/stats.txt** - Full stats for (16, 2048, 2048)

## Metrics Extracted

According to the project specifications:

1. Execution time: `sim_seconds`
2. # cycles: `system.cpu.numCycles`
3. # instructions: `system.cpu.committedInsts`
4. CPI: Calculated as cycles/instructions
5. # Dcache hit/miss: `system.cpu.dcache.overall_hits/misses`
6. # Icache hit/miss: `system.cpu.icache.overall_hits/misses`
7. # L2 cache hit/miss: `system.l2.overall_hits/misses`
8. # branch: `system.cpu.Branches`
9. # branch miss: Not available for TimingSimpleCPU (use DerivO3CPU)
10. # DRAM read/write request: `system.mem_ctrls.dram.num_reads/writes`
11. Row buffer read/write hit: `system.mem_ctrls.dram.read/writeRowHits`

## Next Steps

Once you generate the optimized code (matmul_opt), run the same simulations and extract the same metrics for comparison.

## Command Template for matmul_opt

```bash
cd /home/joon/Documents/proj/KU-2025-2nd-Semester/compiler/Assignments/project_5/gem5
./build/ARM/gem5.opt -d <output_dir> configs/example/se.py \
  --cmd=/path/to/matmul_opt \
  --options="M K N 1" \
  --cpu-type=TimingSimpleCPU \
  --cpu-clock=3GHz --sys-clock=3GHz --num-cpus=1 \
  --caches --l2cache \
  --l1i_size=32kB --l1i_assoc=8 \
  --l1d_size=32kB --l1d_assoc=8 \
  --l2_size=256kB --l2_assoc=8 \
  --cacheline_size=64 \
  --mem-type=DDR3_1600_8x8 --mem-size=1GB
```
