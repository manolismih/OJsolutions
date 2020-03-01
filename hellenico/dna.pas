PROGRAM dna;

VAR
  numofnoukleotidia, periodos, i, j, k, incaradina, tmpalages, finalalages : integer;
  noukleotidia, caradina : array[1..1000] of 1..4;
  alages : array[1..1000] of integer;
  mychar : char;
  input, output : text;

procedure apomonosi(periodika, periodos :integer);
var helpar : array[1..4] of integer;
    perisotera, indicator, i, j : integer;
  begin
  i := 0;
  j := periodika-periodos;
  incaradina := 0;
  while j+periodos <= numofnoukleotidia do
    begin
    j := j+periodos;
    i := i+1;
    caradina[i] := noukleotidia[j];
    incaradina := incaradina+1;
    end;
  for i := 1 to 4 do
    helpar[i] := 0;
  for i := 1 to incaradina do
    helpar[caradina[i]] := helpar[caradina[i]]+1;
  perisotera :=0;
  for i := 1 to 4 do
    if helpar[i] > perisotera then
      begin
      perisotera := helpar[i];
      indicator := i;
      end;
  for i:= 1 to 4 do
    if i <> indicator then
      tmpalages := tmpalages + helpar[i];
    end;

BEGIN
  assign (input, 'dna.in');
  assign (output, 'dna.out');
  reset (input);
  rewrite (output);
  readln (input, numofnoukleotidia, periodos);
  for i:= 1 to numofnoukleotidia do
    begin
      read (input, mychar);
      case mychar of
        'A': noukleotidia[i] := 1;
        'C': noukleotidia[i] := 2;
        'G': noukleotidia[i] := 3;
        'T': noukleotidia[i] := 4;
        end;
      end;
  k := 0;
  finalalages := 32767;
  for i := periodos downto 1 do
    begin
    tmpalages := 0;
    k := k+1;
    for j := 1 to i do
      begin
      apomonosi(j,i);
      alages[k] := tmpalages;
      end;
    end;
  for i := 1 to k do
    if alages[i] < finalalages then
      finalalages := alages[i];
  writeln (output, finalalages);
  close (input);
  close (output);
  end.






