PROGRAM miners;

TYPE
  array2 = array[1..2,1..2] of byte;

VAR
  input, output : text;
  n, i : longint;
  foods : array[1..100000] of byte;
  metriseis : array[1..100000,1..91] of longint;
  codes : array[0..3,0..3,0..3,0..3] of byte;
  nullarray : array2;
  a : char;

procedure gencodes;
var
  code, skip, skipped : shortint;
  left1, left2, right1, right2 : byte;

begin
  skip := -1;
  code := 14;
  for left1 := 0 to 3 do
    for left2 := 1 to 3 do
    begin
      skipped := 0;
      skip := skip+1;
      for right1 := 0 to 3 do
        for right2 := 1 to 3 do
          if skipped = skip then
          begin
            codes[left1,left2,right1,right2] := code;
            codes[right1,right2,left1,left2] := code;
            code := code+1;
            end
          else
            skipped := skipped+1;
      end;

  code := 2;
  left1 := 0;
  left2 := 0;
  for right1 := 0 to 3 do
    for right2 := 1 to 3 do
    begin
      codes[left1,left2,right1,right2] := code;
      codes[right1,right2,left1,left2] := code;
      code := code+1;
      end;

  codes[0,0,0,0] := 1;
  end;

function best(food : longint; mines : array2) : longint;
var a, b : longint; code, i : byte;

        function getcoal(minetogo : byte) : byte;
        begin
          if mines[minetogo,1] = mines[minetogo,2] then
            if (foods[food] = mines[minetogo,1]) or (foods[food] = mines[minetogo,2]) then
              getcoal := 1
            else
              getcoal := 2
          else
            if (foods[food] = mines[minetogo,1]) or (foods[food] = mines[minetogo,2]) then
              getcoal := 2
            else
              getcoal := 3;
          if (mines[minetogo,1] = 0) or (mines[minetogo,2] = 0) then
            getcoal := getcoal - 1;
          end;

        function getmines(minetogo : byte) : array2;
        begin
          getmines := mines;
          getmines[minetogo,1] := getmines[minetogo,2];
          getmines[minetogo,2] := foods[food];
          end;

begin
  code := codes[mines[1,1],mines[1,2],mines[2,1],mines[2,2]];
  if metriseis[food,code] > 0 then
    exit(metriseis[food,code]);

  if food = n then
  begin
    a := getcoal(1);
    b := getcoal(2);
    if a > b then
    begin
      metriseis[food,code] := a;
      exit(a);
      end
    else
    begin
      metriseis[food,code] := b;
      exit(b);
      end;
    end;

  a := getcoal(1) + best(food+1,getmines(1));
  b := getcoal(2) + best(food+1,getmines(2));
  if a > b then
    begin
      metriseis[food,code] := a;
      exit(a);
      end
    else
    begin
      metriseis[food,code] := b;
      exit(b);
      end;

  end;

BEGIN
  readln(n);
  for i := 1 to n do
  begin
    read(a);
    case a of
      'F' : foods[i] := 1;
      'M' : foods[i] := 2;
      'B' : foods[i] := 3;
      end;
    end;
  gencodes;
  writeln(best(1,nullarray));
  END.
