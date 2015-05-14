import g4p_controls.*;

// Need G4P library
import g4p_controls.*;


public void setup(){
  size(480, 320, JAVA2D);
  createGUI();
  customGUI();
  // Place your setup code here
  if(keyPressed && key == 'r'){
    nbp = 0;
  }
}

public void draw(){
  background(230);
  if(windowexists && nbp>=3){
    button2 = new GButton(this, 198, 199, 80, 30);
    button2.setText("Finir");
    button2.addEventHandler(this, "button2_click1");
  }
}

// Use this method to add additional statements
// to customise the GUI controls
public void customGUI(){

}
