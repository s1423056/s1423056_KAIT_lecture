int nCells = 10;
int[] cells = new int[nCells];

void setupCells(){
  for(int i=0;i<nCells;i++){
    cells[i] = int( random(0,2) );
  }
}

void evolve(){
  int[] rules = {0, 0 , 0 , 0 , 1 , 1 , 1 , 0 };
  int[] ng = new int[nCells];
  for(int i=0;i<nCells;i++){
    int left = (i-1+nCells) % (nCells) ;
    int right = (i+1+nCells) % (nCells);
    int v = 4 *cells[left] + 2 *cells[i] + cells[right];
    println(cells[left],cells[i],cells[right]);
    ng[i] = rules[v];
  }
  for(int i=0;i<nCells;i++){
    cells[i] = ng[i];
  }
}
  
void display(int[] c,float y){
  stroke(0);
  for(int i=0;i<nCells;i++){
    if(c[i] == 1){
      fill( 255 );
    }else{
      fill( 0 );
    }
    rect(4*i,y,4,4);
  }
}
  
void setup(){
  size(400,100);
  smooth();
  setupCells();
}

void draw(){
  background(150);
  evolve();

  display(cells,height/2-4/2);
 
}
