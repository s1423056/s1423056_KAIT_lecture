int offset = 10;
int indent = 10;
size(400,400);
smooth();
noStroke();
background( 255, 127, 0);
fill( 0,127 ,255 );
for(int y = 0; y <20 ;y++){
  for(int x = 0; x <21 ;x++){
    ellipse(offset+ 20*x, 10+20*y,15 ,15 );
  }
  offset = indent - offset;
}
