from instruction import Instruction
from instruction import str_to_name
from instruction import str_to_value

def error(msg):
	print("[!!] " + msg)

class Parser():
	# Converts a string to and Instruction
	def line_to_instruction(self,s):	
		
		# Conversion
		
		# remove endline
		words = s.replace("\n","")
		
			
		
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

	def split_comma(self,lines):
		result = []
		for line in lines:
			if ',' in line:
				split_line = line.split(",")
				for s in split_line:
					result.append(s)	
			else:
				result.append(line)
		return result

	def remove_trailing_spaces(self,lines):
		result = []
		for line in lines:
			while line[0]==" ":
				line = line[1:]
			result.append(line)
		return result
	
	def clean_lines(self, lines):
		result = []
		for line in lines:
			if line[0]==";":
				continue

			line = line.replace("\n","")
			line = line.replace("	","")			
			
			# shave off comments
			if ";" in line:
				line = line.split(";")[0]
			
			if len(line)>1:
				result.append(line)
		return result
	
	def assign_labels(self, lines):
		temp = []
		
		label_dict = {}

		i=0
		for line in lines:		
			# assign labels
			if ":" in line:
				name = line.split(":")[1]
				value = label_dict.get(name)
				if value == None:
					label_dict[name] = i	
			else:
				i = i + 1
				temp.append(line)

		result = []

		for line in temp:
			# replace labels
			for lbl in label_dict.keys():
				s = str(lbl)
				if s==line.split(" ")[1]:
					line = line.replace(s,str(label_dict[lbl]))
			result.append(line)

		return result

	# Converts a list of strings
	# to a list of Instructions
	def lines_to_assembly(self,lines):
		instr_list = []
		
		lines = self.split_comma(lines)
		lines = self.remove_trailing_spaces(lines)
		lines = self.clean_lines(lines)
		lines = self.assign_labels(lines)
		
		i=0
		for line in lines:
			instr = self.line_to_instruction(line)
			if instr is not None:
				instr_list.append(instr)
				i = i + 1	
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

