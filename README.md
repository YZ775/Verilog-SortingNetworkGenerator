# Verilog Sorting Network Generator
This project is generator of sorting network on verilog

## Description


BatcherOddEven.py
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;----create sorting network json file

generate_module.py  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;----create module from network json file  

generate_call.py  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;----create top module of sorting network module


Json structure is derived from https://pages.ripco.net/~jgamble/nw.html

## Usage

```
python NetworkGenerator/BatcherOddEven.py N jsonfile.json
```

```
python VerilogGenerator/generate_module.py  jsonfile.json > output.v
```

```
python VerilogGenerator/generate_call.py N > call_output.v
```
N:Sorting Network input size  

This generator outputs code on <i>stdout</i>, so use redirect for saving generated codes.


## Appendix
This generator was developed in AppliedLaboratory class of Engeneering System , University of Tsukuba 
