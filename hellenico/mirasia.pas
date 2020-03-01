PROGRAM mirasia;
VAR
  filoi, antzougies, min, i : integer;
  input, output : text;

BEGIN
  assign(input,'unfair.in');
  reset(input);
  assign(output,'unfair.out');
  rewrite(output);
  readln(input,filoi,antzougies, min);
  for i := 1 to filoi-1 do
  begin
    antzougies := antzougies-min;
    min := min+1;
    end;
  writeln(output,antzougies);
  close(output);
  end.