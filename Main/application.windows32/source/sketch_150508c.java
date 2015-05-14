import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import g4p_controls.*; 
import g4p_controls.*; 
import g4p_controls.*; 
import java.io.BufferedWriter; 
import java.io.File; 
import java.io.FileWriter; 
import java.io.FileInputStream; 
import java.io.FileNotFoundException; 
import java.io.FileOutputStream; 
import java.io.IOException; 
import java.nio.channels.FileChannel; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class sketch_150508c extends PApplet {



// Need G4P library



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
/* =========================================================
 * ====                   WARNING                        ===
 * =========================================================
 * The code in this tab has been generated from the GUI form
 * designer and care should be taken when editing this file.
 * Only add/edit code inside the event handlers i.e. only
 * use lines between the matching comment tags. e.g.

 void myBtnEvents(GButton button) { //_CODE_:button1:12356:
     // It is safe to enter your event code here  
 } //_CODE_:button1:12356:
 
 * Do not rename this tab!
 * =========================================================
 */










 
 
boolean windowexists = false;
String path="";
String imagename;
PImage img1;
String coord;

boolean locked = false;
double points[]=new double[8];
double ref[] = new double[8];
int nbp = 0;
double[] center = new double[2];
double[] inter = new double[4];
double r;
double rref;
double l = 1.0f;
double ldrag;
int dragX;
int dragY;
double tetha;
double Pi=3.14159f;
int sd = -1;

public void textfield1_change1(GTextField source, GEvent event) { //_CODE_:textfield1:312808:
  println("textfield1 - GTextField >> GEvent." + event + " @ " + millis());
  path = source.getText();
  println(path);
} //_CODE_:textfield1:312808:

public void button1_click1(GButton source, GEvent event) { //_CODE_:button1:634745:
  println("button1 - GButton >> GEvent." + event + " @ " + millis());
  int k = path.length()-1;
  if(!path.equals("")){
    while(k>-1 && !path.substring(k,k+1).equals("\\")){k--;}
    if(k!=-1){
      imagename = path.substring(k+1,path.length());
      path = path.substring(0,k+1);
      println(imagename);
      println(path);
      if(!windowexists){
        window1 = new GWindow(this, imagename, 0, 0, 240, 120, false, JAVA2D);
        copy_to_data();
        img1= loadImage(imagename);
        window1.addData(new MyWinData());
        window1.addMouseHandler(this, "windowMouse");
        window1.addDrawHandler(this, "win_draw2");
        window1.setActionOnClose(GWindow.CLOSE_WINDOW);
        windowexists = true;
      }
    }
  }
} //_CODE_:button1:634745:

public void button2_click1(GButton source, GEvent event) { //_CODE_:button2:263596:
  println("button2 - GButton >> GEvent." + event + " @ " + millis());
  if(nbp>=3){
    copy_to_source();
  }
  nbp=0;
  window1.close();
  windowexists = false;
} //_CODE_:button2:263596:

public void button3_click1(GButton source, GEvent event) {
  println("button3 - GButton >> GEvent." + event + " @ " + millis());
  nbp=0;
}

synchronized public void win_draw2(GWinApplet appc, GWinData data) { //_CODE_:window1:581472:
  
  //println(nbp);
  
  MyWinData data2 = (MyWinData)data;
  
  appc.size(img1.width, img1.height);
  appc.background(img1);
  
  if(keyPressed && key == 'r'){
    nbp = 0;
  }
  
  if(keyPressed && key == 'p' && nbp>2 && !locked){
    locked = true;
    for(int k = 0; k<4; k++){
      print("("+(float)points[2*k]+","+(float)points[2*k+1]+"); ");
    }
    print('\n');
    locked = false;
  }
  
  for(int k = 0; k < nbp ; k++){
    appc.fill(255);
    appc.ellipse((int)points[2*k], (int)points[2*k+1], 8, 8);
    if(nbp == 3){
      appc.ellipse((int)points[6], (int)points[7], 8, 8);
      appc.line((int)points[0],(int)points[1],(int)points[4],(int)points[5]);
      appc.line((int)points[2],(int)points[3],(int)points[4],(int)points[5]);
      appc.line((int)points[0],(int)points[1],(int)points[6],(int)points[7]);
      appc.line((int)points[2],(int)points[3],(int)points[6],(int)points[7]);
    }
  }
  if(nbp==2){
    l= Math.sqrt(Math.pow((center[0]-data2.ex),2)+Math.pow((center[1]-data2.ey),2));
    inter[0] = (center[0]-rref*(center[0]-data2.ex)/l);
    inter[1] = (center[1]-rref*(center[1]-data2.ey)/l);
    inter[2] = 2*center[0] - inter[0];
    inter[3] = 2*center[1] - inter[1];
    appc.fill(125);
    appc.ellipse((int)inter[0], (int)inter[1], 8, 8);
    appc.ellipse((int)inter[2], (int)inter[3], 8, 8);
  }
  if(nbp >= 2){
    appc.ellipse((int)center[0], (int)center[1], 8, 8);
  }
  
  if (mousePressed && !locked && nbp<3) {
    stroke(255);
    points[2*nbp]=data2.ex;
    points[2*nbp+1]=data2.ey;
    nbp = min((nbp+1),3);
    if(nbp==3){
      points[4] = inter[0];
      points[5] = inter[1];
      points[6] = inter[2];
      points[7] = inter[3];
      update_ref();
    }
    locked = true;
    /*for(int k = 0; k<2*nbp; k++){
      System.out.println(points[k]);
    }
    System.out.println(nbp);
    System.out.println(' ');*/
    if(nbp==2){
      center[0]=(points[0]+points[2])/2.0f;
      center[1]=(points[1]+points[3])/2.0f;
      r = Math.sqrt(Math.pow((center[0]-points[0]),2)+Math.pow((center[1]-points[1]),2));
      rref = r;
    }
  } else if(mousePressed && !locked && nbp==3){
    for(int k = 0; k<4; k++){
      if(Math.sqrt(Math.pow((data2.ex-points[2*k]),2)+Math.pow((data2.ey-points[2*k+1]),2))<=4.0f){
        sd = k;
        locked = true;
        rref=r;
      }
    }
    if(Math.sqrt(Math.pow((data2.ex-center[0]),2)+Math.pow((data2.ey-center[1]),2))<=4.0f){
      sd = 4;
      dragX = data2.ex;
      dragY = data2.ey;
      locked = true;
      rref=r;
    }
  }else if(mousePressed && locked && sd>-1){
    if(sd<4){
      int sd2=0;
      if(sd==0){sd2 = 1;}
      if(sd==1){sd2 = 0;}
      if(sd==2){sd2 = 3;}
      if(sd==3){sd2 = 2;}
      l= Math.sqrt(Math.pow((center[0]-data2.ex),2)+Math.pow((center[1]-data2.ey),2));
      points[2*sd] = (center[0]-r*(center[0]-data2.ex)/l);
      points[2*sd+1] = (center[1]-r*(center[1]-data2.ey)/l);
      points[2*sd2] = 2*center[0] - points[2*sd];
      points[2*sd2+1] = 2*center[1] - points[2*sd+1];
      update_ref();
    }else{
      int dx = data2.ex-dragX;
      int dy = data2.ey-dragY;
      dragX = data2.ex;
      dragY = data2.ey;
      for(int k = 0; k<4 ; k++){
        points[2*k] += dx;
        points[2*k+1] += dy;
        update_ref();
      }
      center[0] += dx;
      center[1] += dy;
    }
  }else if(!mousePressed && locked){
    stroke(0);
    locked = false;
    sd = -1;
  }
  appc.line(data2.ex-66, data2.ey, data2.ex+66, data2.ey);
  appc.line(data2.ex, data2.ey-66, data2.ex, data2.ey+66); 

} //_CODE_:window1:581472:



// Create all the GUI controls. 
// autogenerated do not edit
public void createGUI(){
  G4P.messagesEnabled(false);
  G4P.setGlobalColorScheme(GCScheme.BLUE_SCHEME);
  G4P.setCursor(ARROW);
  if(frame != null)
    frame.setTitle("Sketch Window");
  textfield1 = new GTextField(this, 40, 110, 400, 18, G4P.SCROLLBARS_NONE);
  textfield1.setOpaque(true);
  textfield1.addEventHandler(this, "textfield1_change1");
  label1 = new GLabel(this, 130, 90, 220, 20);
  label1.setText("Entrez le chemin de l'image");
  label1.setOpaque(false);
  button1 = new GButton(this, 180, 134, 116, 30);
  button1.setText("Lancer l'application");
  button1.addEventHandler(this, "button1_click1");
  button3 = new GButton(this, 180, 250, 116, 30);
  button3.setText("Recommencer");
  button3.addEventHandler(this, "button3_click1");
}

// Variable declarations 
// autogenerated do not edit
GTextField textfield1; 
GLabel label1; 
GButton button1; 
GButton button2;
GButton button3;
GWindow window1;

public void copy_to_source(){
  
  int k = imagename.length()-1;
  while(k>0 && imagename.substring(k,k+1)!="."){k--;}
  coord = imagename.substring(0,k+1)+".txt";
  File destFile = new File(path+coord);

 try {
 
      String content = "P1 : ("+points[0]+","+points[1]+")\n"+
                       "P2 : ("+points[2]+","+points[3]+")\n"+
                       "P3 : ("+points[4]+","+points[5]+")\n"+
                       "P4 : ("+points[6]+","+points[7]+")\n";
 
      File file = new File(path+coord);
 
      // if file doesnt exists, then create it
      if (!file.exists()) {
        file.createNewFile();
      }
 
      FileWriter fw = new FileWriter(file.getAbsoluteFile());
      BufferedWriter bw = new BufferedWriter(fw);
      bw.write(content);
      bw.close();
 
      System.out.println("Done");
 
    } catch (IOException e) {
      e.printStackTrace();
    }
 
}

public void copy_to_data() {
  
  File sourceFile = new File(path+imagename);
  File destFile = new File(dataPath(imagename));


  /* verify whether file exist in source location */
  if (!sourceFile.exists()) {
    println("Source File Not Found!");
  }

  /* if file not exist then create one */
  if (!destFile.exists()) {
    try {
      destFile.createNewFile();
      
      println("Destination file doesn't exist. Creating one!");
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  FileChannel source = null;
  FileChannel destination = null;

  try {

    /**
     * getChannel() returns unique FileChannel object associated a file
     * output stream.
     */
    source = new FileInputStream(sourceFile).getChannel();

    destination = new FileOutputStream(destFile).getChannel();

    if (destination != null && source != null) {
      destination.transferFrom(source, 0, source.size());
    }

  } catch (FileNotFoundException e) {
    e.printStackTrace();
  } catch (IOException e) {
    e.printStackTrace();
  }

  finally {
    if (source != null) {
      try {
        source.close();
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
    if (destination != null) {
      try {
        destination.close();
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
  }
}

public void windowMouse(GWinApplet appc, GWinData data, MouseEvent event) {
  MyWinData data2 = (MyWinData)data;
  data2.ex = appc.mouseX;
  data2.ey = appc.mouseY;
  switch(event.getAction()) {
  case MouseEvent.PRESS:
    mousePressed = true;
    break;
  case MouseEvent.RELEASE:
    data2.ex = appc.mouseX;
    data2.ey = appc.mouseY;
    mousePressed = false;
    break;
  }
}

class MyWinData extends GWinData {
  int sx, sy, ex, ey;
  boolean done;
}

public void update_ref(){
  for(int k = 0 ; k<8; k++){ref[k] = points[k];}
}

public void mouseWheel(MouseEvent event) {
  double e = event.getCount();
  if(nbp >= 2 && !locked){
    r = r + e;
    for(int k = 0; k<4; k++){
      points[2*k] = (center[0]+r*(ref[2*k]-center[0])/rref);
      points[2*k+1] = (center[1]+r*(ref[2*k+1]-center[1])/rref);
    }
  }
}
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_150508c" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
