module mux2 #(parameter WIDTH = 32)
		     (input  logic               s,
			  input  logic [WIDTH - 1:0] d0, d1,
			  output logic [WIDTH - 1:0] y);
	
	assign y = s ? d1 : d0;
endmodule