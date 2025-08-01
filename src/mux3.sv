module mux3 #(parameter WIDTH = 32)
		     (input  logic         [1:0] s,
			  input  logic [WIDTH - 1:0] d0, d1, d2,
			  output logic [WIDTH - 1:0] y);
			  
	assign y = s[1] ? d2 : (s[0] ? d1 : d0);
	
endmodule 