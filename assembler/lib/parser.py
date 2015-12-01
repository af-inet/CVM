from instruction import Instruction
from instruction import str_to_name
from instruction import str_to_value

class Parser():
    # Converts a string to and Instruction
    def line_to_instruction(self,s):    
        
        # Conversion
        
        # remove endline
        words = s.replace("\n","")
        
        # shave off comments
        if ";" in words:
            words = words.split(";")[0]    
        
        words = words.split(" ")
        
        # ignore lines with less than 2 words
        if len(words)<2:
            return None

        str_name  = words[0].lower()
        str_value = words[1]
        num_name  = str_to_name(str_name)
        num_value = str_to_value(str_value)
        
        # Error Checking
        if num_name is None:
            error("Invalid Instruction " + str_name)
            return None

        if num_value is None:
            error("Invalid Value " + str_value)
            return None
        
        return Instruction(num_name,num_value)

    # Converts a list of strings
    # to a list of Instructions
    def lines_to_assembly(self,lines):
        instr_list = []
        for line in lines:
            instr = self.line_to_instruction(line)
            if instr is not None:
                instr_list.append(instr)
        return instr_list

    # Converts a list of instructions
    # to a list of bytes.
    def assembly_to_buffer(self,assembly):
        buf = []
        for instr in assembly:
            name = chr(instr.name)
            value = chr(instr.value)
            buf.append(name)
            buf.append(value)
        return buf

