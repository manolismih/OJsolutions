PROGRAM crocodiles;

VAR
  numofcrocodiles, i, a, b : longint;
  krokodili : array[-100000..100000] of longint;
  input, output : text;

BEGIN
  assign(input,'crocodiles.in');
  reset(input);
  assign(output,'crocodiles.out');
  rewrite(output);
  readln(input,numofcrocodiles);
  for i := 1 to numofcrocodiles do
  begin
    readln(input,a,b);
    krokodili[a] := krokodili[a]+1;
    krokodili[b] := krokodili[b]-1;
    end;
  a := 0;
  b := 0;
  for i := -100000 to 100000 do
    if krokodili[i] <> 0 then
    begin
      a := a+krokodili[i];
      if a > b then
        b := a;
      end;
  writeln(output,b);
  close(input);
  close(output);
  end.
