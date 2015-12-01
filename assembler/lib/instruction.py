
# For converting from Instruction bytes to names.
instr_list = [
    "halt",
    "adda",
    "addv",
    "suba",
    "subv",
    "jmpa",
    "jmpv",
    "jmpi",
    "seta",
    "setv",
    "ptra",
    "ptrv"
]

# For Instruction names to bytes
instr_map = {
	"halt":0x0,
	"adda":0x1,
	"addv":0x2,
	"suba":0x3,
	"subv":0x4,
	"jmpa":0x5,
	"jmpv":0x6,
	"jmpi":0x7,
	"seta":0x8,
	"setv":0x9,
	"ptra":0xA,
	"ptrv":0xB
}

# Instruction Model
class Instruction():
    def __init__(self,name,value):
        self.name  = name
        self.value = value

def str_to_name(s):
    return instr_map.get(s)

def str_to_value(s):
    try:
        num = int(s)
        return num
    except:
        return None

def num_to_str(n):
    return instr_list[n]

