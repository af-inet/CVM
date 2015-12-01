import sys
import argparse
from lib.assembler import Assembler

def parse_args():

    parser = argparse.ArgumentParser("assembler")

    parser.add_argument(
        "filename",
        type=str,
        help="input file"
    )

    parser.add_argument(
        "-o",
        type=str,
        help="output destination",
        required=False,
        metavar="output",
        dest="output",
        default=None
    )

    args = parser.parse_args()
    
    return args

def __main__(): 
    args = parse_args()
    
    if args.output is None:
        args.output = args.filename + ".asm"

    f_input  = args.filename
    f_output = args.output
    
    asm = Assembler()
    asm.assemble(f_input,f_output)

__main__()
