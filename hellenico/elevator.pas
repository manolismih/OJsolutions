program elevator;

var
  numofdolphins, diadromes, baros, i, j, k : longint;
  peritos : boolean;
  dolphins, helpar : array[0..100000] of longint;
  input, output : text;
begin
  assign (input, 'elevator.in');
  assign (output, 'elevator.out');
  reset (input);
  rewrite (output);
  readln (input, numofdolphins);
  for i := 1 to numofdolphins do
    readln (input, dolphins[i]);
  for i := 1 to 100000 do
    helpar[i] := 0;
  for i := 1 to 100000 do
    helpar[dolphins[i]] := helpar[dolphins[i]] + 1;
  k := 0;
  for i := 1 to 100000 do
    for j := 1 to helpar[i] do
    begin
    k := k + 1;
    dolphins[k] := i
    end;
  diadromes := 0;
  peritos := false;
  if numofdolphins mod 2 > 0 then
    begin
    numofdolphins := numofdolphins-1;
    diadromes := diadromes+1;
    peritos := true
    end;
  baros := 0;
  for i := 1 to numofdolphins div 2 do
    if dolphins[i] + dolphins[numofdolphins+1-i] > baros then
      baros := dolphins[i] + dolphins[numofdolphins+1-i];
  diadromes := diadromes + numofdolphins div 2;
  if peritos = true then
    if dolphins[numofdolphins+1] > baros then
      baros := dolphins[numofdolphins+1];
  write (output, diadromes,' ',baros);
  close (input);
  close (output);
end.

