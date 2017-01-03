int nCells = 100;
int[] cells = new int[nCells];
int[] pcells = new int[nCells];

void setupCells(){
  for(int i=0;i<nCells;i++){
    cells[i] = int( random(0,2) );
    pcells[i] = cells[i];
  }
}

void copycells(){
  for(int i = 0;i < nCells;i++){
    pcells[i] = cells[i];
  } 
}

void evolve(){
  int[] ng = new int[nCells];
  for(int i=0;i<nCells;i++){
    int left = i-1;
    int right = i+1;
    if(left == -1){
      left = nCells-1 ;
    }
    if(right == nCells){
      right = 0 ;
    }
    if(cells[i] == 0){
      ng[i] = 0 ;
      if( cells[left] == 1 ){
        ng[i] = 1;
      }
    }else{
      ng[i] = 1;
      if( cells[left] == 1 && cells[right] == 1 ){
        ng[i] = 0;
      }else if( cells[left] == 0 && cells[right] == 0 ){
        ng[i] = 0;
      }
    }
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
  copycells();
  evolve();

  display(cells,height/2-4/2);
 
}
