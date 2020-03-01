{
ID:manolis2
PROG:sort3
LANG:PASCAL
}
PROGRAM sort3;

VAR
  n, antalages, i, a : integer;
  helpar : array[1..3] of integer;
  stoixeia : array[1..2,1..2] of integer;
  input, output : text;

BEGIN
  assign(input,'sort3.in');
  reset(input);
  assign(output,'sort3.out');
  rewrite(output);
  readln(input,n);
  for i := 1 to n do
  begin
    readln(input,a);
    helpar[a] := helpar[a]+1;
    end;
  reset(input);
  readln(input);
  for i := 1 to helpar[1] do
  begin
    readln(input,a);
    if a = 2 then
      stoixeia[1,1] := stoixeia[1,1]+1;
    if a = 3 then
      stoixeia[1,2] := stoixeia[1,2]+1;
    end;
  for i := 1 to helpar[2] do
    readln(input);
  for i := 1 to helpar[3] do
  begin
    readln(input,a);
    if a = 2 then
      stoixeia[2,1] := stoixeia[2,1]+1;
    if a = 1 then
      stoixeia[2,2] := stoixeia[2,2]+1;
    end;
  if stoixeia[1,2] < stoixeia[2,2] then
    antalages := stoixeia[1,2]
  else
    antalages := stoixeia[2,2];
  stoixeia[1,2] := stoixeia[1,2]-antalages;
  stoixeia[2,2] := stoixeia[2,2]-antalages;
  antalages := antalages+stoixeia[1,1]+stoixeia[1,2]+stoixeia[2,1]+stoixeia[2,2];
  writeln(output,antalages);
  close(input);
  close(output);
  end.
