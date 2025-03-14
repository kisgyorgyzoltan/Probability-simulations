using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class Automate : MonoBehaviour
{
    public static List<string> moveList = new List<string>() { };
    // public static List<string> reverseList = new List<string>() { };
    private readonly List<string> allMoves = new List<string>()
        { "U", "D", "L", "R", "F", "B",
          //"U2", "D2", "L2", "R2", "F2", "B2",
          "U'", "D'", "L'", "R'", "F'", "B'" 
        };

    private CubeState cubeState;
    private ReadCube readCube;
// ---------------------------------
    public Transform up;
    public Transform down;
    public Transform left;
    public Transform right;
    public Transform front;
    public Transform back;

    public Transform up_s;
    public Transform down_s;
    public Transform left_s;
    public Transform right_s;
    public Transform front_s;
    public Transform back_s;
    private int k;
    public int l;
    public Material feher;
    public Material fekete;
    public Material zold;


    private int ok = 0;
    private float time = 0;
    private float mozogTime = 0;


// ------------------------------------ 

    // Start is called before the first frame update
    void Start()
    {
        k=0;
        cubeState = FindObjectOfType<CubeState>();
        saveState(cubeState.front, front_s);
        saveState(cubeState.back, back_s);
        saveState(cubeState.left, left_s);
        saveState(cubeState.right, right_s);
        saveState(cubeState.up, up_s);
        saveState(cubeState.down, down_s);
        
        // reverseList.Clear();
        readCube = FindObjectOfType<ReadCube>();
    }

    public void upadteMap(List<GameObject> face, Transform side){
        int i = 0;
        foreach (Transform map in side)
        {
            if (face[i].name[0] == 'F')
            {
                // map.GetComponent<Image>().color = Color.grey;
                map.GetComponent<Image>().color = face[i].GetComponent<Renderer>().material.color;
            }
            if (face[i].name[0] == 'B')
            {
                // map.GetComponent<Image>().color = Color.red;
                map.GetComponent<Image>().color = face[i].GetComponent<Renderer>().material.color;
            }
            if (face[i].name[0] == 'U')
            {
                // map.GetComponent<Image>().color = Color.yellow;
                map.GetComponent<Image>().color = face[i].GetComponent<Renderer>().material.color;
            }
            if (face[i].name[0] == 'D')
            {
                // map.GetComponent<Image>().color = Color.white;
                map.GetComponent<Image>().color = face[i].GetComponent<Renderer>().material.color;
            }
            if (face[i].name[0] == 'L')
            {
                // map.GetComponent<Image>().color = Color.green;
                map.GetComponent<Image>().color = face[i].GetComponent<Renderer>().material.color;
            }
            if (face[i].name[0] == 'R')
            {
                // map.GetComponent<Image>().color = Color.blue;
                map.GetComponent<Image>().color = face[i].GetComponent<Renderer>().material.color;
            }
            i++;
        } 
    }

    public void saveState(List<GameObject> face, Transform side)
    {
        int i = 0;
        foreach (Transform map in side)
        {
            if (face[i].name[0] == 'F')
            {
                // map.GetComponent<Image>().color = Color.grey;
                map.GetComponent<Image>().color = face[i].GetComponent<Renderer>().material.color;
            }
            if (face[i].name[0] == 'B')
            {
                // map.GetComponent<Image>().color = Color.red;
                map.GetComponent<Image>().color = face[i].GetComponent<Renderer>().material.color;
            }
            if (face[i].name[0] == 'U')
            {
                // map.GetComponent<Image>().color = Color.yellow;
                map.GetComponent<Image>().color = face[i].GetComponent<Renderer>().material.color;
            }
            if (face[i].name[0] == 'D')
            {
                // map.GetComponent<Image>().color = Color.white;
                map.GetComponent<Image>().color = face[i].GetComponent<Renderer>().material.color;
            }
            if (face[i].name[0] == 'L')
            {
                // map.GetComponent<Image>().color = Color.green;
                map.GetComponent<Image>().color = face[i].GetComponent<Renderer>().material.color;
            }
            if (face[i].name[0] == 'R')
            {
                // map.GetComponent<Image>().color = Color.blue;
                map.GetComponent<Image>().color = face[i].GetComponent<Renderer>().material.color;
            }
            i++;
        }   
        // RevSet();            
    }
    void loadState(List<GameObject> face, Transform side)
    {
        int i = 0;
        foreach (Transform map in side)
        {
            if (face[i].name[0] == 'F')
            {
                // map.GetComponent<Image>().color = Color.grey;
                face[i].GetComponent<Renderer>().material.color = map.GetComponent<Image>().color;
            }
            if (face[i].name[0] == 'B')
            {
                // map.GetComponent<Image>().color = Color.red;
                face[i].GetComponent<Renderer>().material.color = map.GetComponent<Image>().color;
            }
            if (face[i].name[0] == 'U')
            {
                // map.GetComponent<Image>().color = Color.yellow;
                face[i].GetComponent<Renderer>().material.color = map.GetComponent<Image>().color;
            }

            if (face[i].name[0] == 'D')
            {
                // map.GetComponent<Image>().color = Color.white;
                face[i].GetComponent<Renderer>().material.color = map.GetComponent<Image>().color;
            }

            if (face[i].name[0] == 'L')
            {
                // map.GetComponent<Image>().color = Color.green;
                face[i].GetComponent<Renderer>().material.color = map.GetComponent<Image>().color;
            }

            if (face[i].name[0] == 'R')
            {
                // map.GetComponent<Image>().color = Color.blue;
                face[i].GetComponent<Renderer>().material.color = map.GetComponent<Image>().color;
            }



            i++;
        }               
    }

    // Update is called once per frame
    void Update()
    {
        // if(moveList.Count==0)
        //     Shuff();
    // Debug.Log("moveList.Count: " + moveList.Count + "Mozogt " + mozogTime + "k=" + k + " CubeState.autoRotating=" + CubeState.autoRotating);

        // && mozogTime <=0 
        if (moveList.Count > 0 && mozogTime <=0  && !CubeState.autoRotating  && CubeState.started && k!=0)
        {
            // Debug.Log("moveList.Count: " + moveList.Count + "time: " + time);
            // zoldToFekete(up);
            // zoldToFekete(down);
            // zoldToFekete(left);
            // zoldToFekete(right);
            // zoldToFekete(front);
            // zoldToFekete(back);
            RevSet();
            mozogTime=0f;
            //Do the move at the first index;
            DoMove(moveList[0]);

            // remove the move at the first index
            moveList.Remove(moveList[0]);
            // saveState();    
        }
        mozogTime -= Time.deltaTime;
         
        // if(moveList.Count == 0 && reverseList.Count !+ 0  && !CubeState.autoRotating && mozogTime <=0 && CubeState.started)
        // {
        //      foreach (var item in reverseList)
        //         {
        //             moveList.Add(item);
        //         }
        //         reverseList.Clear();
                
        // }>

        

        if(moveList.Count == 0 && k!=0){

            if(k!=0 && time <=0)
            {
                time = 1;
                continueSuffle();
                
                // foreach (var item in reverseList)
                // {
                //     moveList.Add(item);
                // }
                // reverseList.Clear();
            }
            
            
            time -= Time.deltaTime;
        }
            
        // }
        
    }

    public void Shuffle()
    {
        zoldToFekete(up);
        zoldToFekete(down);
        zoldToFekete(left);
        zoldToFekete(right);
        zoldToFekete(front);
        zoldToFekete(back);
        RevSet();
        
        k=l;
        mozogTime=1f;
        
    }

    public void Shuff()
    {
        
        List<string> moves = new List<string>();
        int shuffleLength = Random.Range(10, 30);
        //  for (int i = reverseList.size; i >= 0 ; i--)
        // {
        //     reverseList.Add(revertmove(moves[i]));
        // }
        // foreach (var a in reverseList){
        //     reverseList.Add(revertmove(a));
        // }
       

        for (int i = 0; i < l; i++)
        {
            int randomMove = Random.Range(0, allMoves.Count);
            moves.Add(allMoves[randomMove]);
        }
        //  for (int i = l-1; i >= 0; i--)
        // {
        //     reverseList.Add(revertmove(moves[i]));
        // }
        moveList = moves;
    }
    private void feketeToZold(Transform a)
    {
        foreach (Transform child in a)
        {
            if (child.GetComponent<Image>().color == fekete.color)
            {
                child.GetComponent<Image>().color = zold.color;
            }
        }
    }
    private void zoldToFekete(Transform a)
    {
        foreach (Transform child in a)
        {
            if (child.GetComponent<Image>().color == zold.color)
            {
                child.GetComponent<Image>().color = fekete.color;
            }
        }
    }

    public void continueSuffle()
    {

            // zoldToFekete(up);
            // zoldToFekete(down);
            // zoldToFekete(left);
            // zoldToFekete(right);
            // zoldToFekete(front);
            // zoldToFekete(back);
            RevSet();
    
            Debug.Log("k" + k);
            
            
            ok=0;
            if(DotsPerSide(up)==4){
                 ok++;
                 feketeToZold(up);
            }
            if(DotsPerSide(down)==4){
                ok++;
                feketeToZold(down);
            }
            if(DotsPerSide(left)==4){
                ok++;
                feketeToZold(left);
            }
            if(DotsPerSide(right)==4){
                ok++;
                feketeToZold(right);
            }
            if(DotsPerSide(front)==4){
                ok++;
                feketeToZold(front);
            }
            if(DotsPerSide(back)==4){
                ok++;
                feketeToZold(back);
            }
           if(ok==3)
           {
                k=0;
                time = 6f;
                mozogTime=5f;
                RevSet();
           }
           else{
                time = 1f;
                mozogTime=2f;

                loadState(cubeState.up,up_s);
                loadState(cubeState.down,down_s);
                loadState(cubeState.left,left_s);
                loadState(cubeState.right,right_s);
                loadState(cubeState.front,front_s);
                loadState(cubeState.back,back_s);

                upadteMap(cubeState.up,up);
                upadteMap(cubeState.down,down);
                upadteMap(cubeState.left,left);
                upadteMap(cubeState.right,right);
                upadteMap(cubeState.front,front);
                upadteMap(cubeState.back,back);

                // RevSet();
                // foreach (var item in reverseList)
                // {
                //     moveList.Add(item);
                // }
                // reverseList.Clear();
                Shuff();
                }
           
      

        
    }

    int DotsPerSide(Transform a)
    {
        int i = 0;
        foreach (Transform child in a)
        {
            if (child.GetComponent<Image>().color == fekete.color)
            {
                i++;
            }
           
        }
        
        return i;
    }

    void DoMove(string move)
    {
        readCube.ReadState();
        CubeState.autoRotating = true;
        if (move == "U")
        {
            RotateSide(cubeState.up, -90);
        }
        if (move == "U'")
        {
            RotateSide(cubeState.up, 90);
        }
        if (move == "U2")
        {
            RotateSide(cubeState.up, -180);
        }
        if (move == "D")
        {
            RotateSide(cubeState.down, -90);
        }
        if (move == "D'")
        {
            RotateSide(cubeState.down, 90);
        }
        if (move == "D2")
        {
            RotateSide(cubeState.down, -180);
        }
        if (move == "L")
        {
            RotateSide(cubeState.left, -90);
        }
        if (move == "L'")
        {
            RotateSide(cubeState.left, 90);
        }
        if (move == "L2")
        {
            RotateSide(cubeState.left, -180);
        }
        if (move == "R")
        {
            RotateSide(cubeState.right, -90);
        }
        if (move == "R'")
        {
            RotateSide(cubeState.right, 90);
        }
        if (move == "R2")
        {
            RotateSide(cubeState.right, -180);
        }
        if (move == "F")
        {
            RotateSide(cubeState.front, -90);
        }
        if (move == "F'")
        {
            RotateSide(cubeState.front, 90);
        }
        if (move == "F2")
        {
            RotateSide(cubeState.front, -180);
        }
        if (move == "B")
        {
            RotateSide(cubeState.back, -90);
        }
        if (move == "B'")
        {
            RotateSide(cubeState.back, 90);
        }
        if (move == "B2")
        {
            RotateSide(cubeState.back, -180);
        }
        
    }


    void RotateSide(List<GameObject> side, float angle)
    {
        // automatically rotate the side by the angle
        PivotRotation pr = side[4].transform.parent.GetComponent<PivotRotation>();
        pr.StartAutoRotate(side, angle);  
            
    }


  void RevSet()
    {
        cubeState = FindObjectOfType<CubeState>();

        ReverseUpdateMap(cubeState.front, front);
        ReverseUpdateMap(cubeState.back, back);
        ReverseUpdateMap(cubeState.left, left);
        ReverseUpdateMap(cubeState.right, right);
        ReverseUpdateMap(cubeState.up, up);
        ReverseUpdateMap(cubeState.down, down);
    }

void ReverseUpdateMap(List<GameObject> face, Transform side){
    int i = 0;
    foreach (Transform map in side)
    {
        if (face[i].name[0] == 'F')
        {
            // map.GetComponent<Image>().color = Color.grey;
            face[i].GetComponent<Renderer>().material.color=map.GetComponent<Image>().color;
        }
        if (face[i].name[0] == 'B')
        {
            // map.GetComponent<Image>().color = Color.red;
            face[i].GetComponent<Renderer>().material.color=map.GetComponent<Image>().color;
        }
        if (face[i].name[0] == 'U')
        {
            // map.GetComponent<Image>().color = Color.yellow;
            face[i].GetComponent<Renderer>().material.color=map.GetComponent<Image>().color;
        }
        if (face[i].name[0] == 'D')
        {
            // map.GetComponent<Image>().color = Color.white;
            face[i].GetComponent<Renderer>().material.color=map.GetComponent<Image>().color;
        }
        if (face[i].name[0] == 'L')
        {
            // map.GetComponent<Image>().color = Color.blue;
            face[i].GetComponent<Renderer>().material.color=map.GetComponent<Image>().color;
        }
        if (face[i].name[0] == 'R')
        {
            // map.GetComponent<Image>().color = Color.green;
            face[i].GetComponent<Renderer>().material.color=map.GetComponent<Image>().color;
        }
        i++;
    } 
}

}
