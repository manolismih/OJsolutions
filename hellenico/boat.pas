program boat;

var
  limania, exerxomena, iserxomena, sinolika, proigsinolika, i, j, k : integer;
  cars : array[0..100000] of string[42];
  tmp : string[42];
  letter : char;
  input, output : text;

begin
  assign (input, 'boat.in');
  assign (output, 'boat.out');
  reset (input);
  rewrite (output);
  readln (input, limania);
  sinolika := 0;
  for i := 1 to limania do
    begin
    read (input, exerxomena, iserxomena);
    read (input, letter);
    proigsinolika := sinolika-exerxomena;
    sinolika := sinolika-exerxomena+iserxomena;
    {setlength (cars, sinolika);}
    for j := proigsinolika to sinolika-1 do
      begin
      cars[j] := '';
      repeat
        read (input, letter);
        if letter <> ' ' then
          cars[j] := cars[j]+letter;
      until (letter = ' ') or (eoln(input))
      end;
    end;
  for i := 0 to sinolika-1 do
    begin
    j := i;
    while (j>0) and (cars[i] < cars[j-1]) do
      j := j-1;
    tmp := cars[i];
    for k := i downto j+1 do
      cars[k] := cars[k-1];
    cars[j] := tmp;
    end;
  for i := 0 to sinolika-1 do
    writeln (output, cars[i]);
  close (input);
  close (output);
  end.
