program test;

var a, b : longint;
    input, output : text;

begin
  assign (input,'addin.txt');
  assign (output,'addout.txt');
  reset (input);
  rewrite (output);
  read (input, a, b);
  writeln (output,a+b);
  close (input);
  close (output);
  end.
