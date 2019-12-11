# Verilog Sorting Network Generator

generate_module.py  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;----create module from network json file  

generate_call.py  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;----create call statement of sorting network module

## Usage

```
python generate_module.py  jsonfile.json > output.v
```

```
python generate_call.py N > call_output.v
```
N:Sorting Network input size  

This generator outputs code on <i>stdout</i>, so use redirect for saving generated codes.


## Appendix
This generator was developed in AppliedLaboratory class of Engeneering System , University of Tsukuba 