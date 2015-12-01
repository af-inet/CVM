from parser import Parser

parse = Parser()

class Assembler():

    # Read file,
    # return assembly buffer.
    def assemble_file(self,filename):
        f = open(filename,"r")
        
        lines = f.readlines()
        assembly = parse.lines_to_assembly(lines)
        buf = parse.assembly_to_buffer(assembly)

        f.close()
        
        return buf
    
    # Assemble input file,
    # write assembly to output file.
    def assemble(self, filename_in, filename_out):        
        assembly = self.assemble_file(filename_in)
        
        f = open(filename_out,"w")
        
        for b in assembly:
            f.write(b)
        
        f.close()


