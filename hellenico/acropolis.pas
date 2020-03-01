program acropolis;

var
  numofmarbles, lightmarble, tmp, indicator, i, j : integer;
  marbles : array[1..1000] of integer;
  input, output : text;
begin
  assign (input, 'acropolis.in');
  assign (output, 'acropolis.out');
  reset (input);
  rewrite (output);
  readln (input, numofmarbles);
  for i := 1 to numofmarbles do
    readln (input, marbles[i]);
  for i := 1 to numofmarbles do
    if marbles[i] > 1 then
      begin
      lightmarble := 9001;
      for j := i to numofmarbles do
        if (marbles[j] < lightmarble) and (marbles[j] > 1) then
          begin
          lightmarble := marbles[j];
          indicator := j
          end;
      tmp := marbles[i];
      marbles[i] := lightmarble;
      marbles[indicator] := tmp
      end;
  for i := 1 to numofmarbles do
    writeln (output, marbles[i]);
  close (input);
  close (output);
  end.

