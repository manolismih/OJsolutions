program namesofdolphins;

var
  names : array[1..1000,1..21] of string[20];
  letter : array[1..21] of char;
  bestversion, bestname : string[20];
  numofnames, numofletters, i, j, k : integer;
  input, output : text;

begin
  assign (input, 'names.in');
  assign (output, 'names.out');
  reset (input);
  rewrite (output);
  readln (input, numofnames);
  for i := 1 to numofnames do
    begin
    numofletters := 0;
    repeat
      numofletters := numofletters + 1;
      read (input,letter[numofletters])
      until eoln(input);
    readln (input);
    for j := 1 to numofletters do
      begin
      for k := 1 to numofletters do
        names[i,j] := names[i,j] + letter[k];
      letter[numofletters+1] := letter[1];
      for k := 1 to numofletters do
        letter[k] := letter[k+1];
      end;
    names[i,21] := 'zzzzz';
    for j := 1 to numofletters do
      if names[i,j] < names[i,21] then
        names[i,21] := names[i,j];
    end;
  bestversion := 'zzzzz';
  for i := 1 to numofnames do
    if names[i,21] < bestversion then
      begin
      bestversion := names[i,21];
      bestname := names[i,1];
      end;
  write (output,bestname);
  close (input);
  close (output);
end.


