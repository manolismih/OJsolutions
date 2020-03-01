PROGRAM qubits;
VAR
  numofqubits : integer;
  input, output : text;

procedure transport(qubitnum : integer; start, destination, other : char);
begin
  if qubitnum = 1 then
    writeln (output,start,' ',destination)
  else
    begin
    transport(qubitnum-1,start,other,destination);
    writeln (output,start,' ',destination);
    transport(qubitnum-1, other, destination, start);
    end;
  end;

BEGIN
  assign (input,'qubits.in');
  reset (input);
  assign (output,'qubits.out');
  rewrite (output);
  readln (input,numofqubits);
  transport (numofqubits,'A','C','B');
  close (input);
  close (output);
  END.
