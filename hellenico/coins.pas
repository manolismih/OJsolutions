PROGRAM stoives_nomismaton;

VAR
  input, output : text;
  k, l, i, games : longint;
  numofcoins : array[1..50] of longint;
  metriseis : array[1..1000000] of char;

function wins(coins : longint; player : char) : char;
var a, b, c : char;

        function switch : char;
        begin
          if player = 'A' then
            switch := 'B'
          else
            switch := 'A';
          end;

begin
  if coins = 0 then
    wins := switch
  else
    if metriseis[coins] <> 'N' then
      if player = 'A' then
        wins := metriseis[coins]
      else
      begin
        player := metriseis[coins];
        wins := switch;
        end
    else
    begin
      a := wins(coins-1,switch);
      if coins-k >= 0 then
        b := wins(coins-k,switch)
      else
        b := 'N';
      if coins-l >= 0 then
        c := wins(coins-l,switch)
      else
        c := 'N';
      if (a = player) or (b = player) or (c = player) then
        wins := player
      else
        wins := switch;
      end;
  end;

BEGIN
  assign(input,'coins.in');
  reset (input);
  assign(output,'coins.out');
  rewrite (output);
  readln(input,k,l,games);
  for i := 1 to games do
    read(input,numofcoins[i]);
  for i := 1 to 1000000 do
  begin
    metriseis[i] := 'N';
    metriseis[i] := wins(i,'A');
    end;
  for i := 1 to games do
    write(output,metriseis[numofcoins[i]]);
  close(output);
  END.
