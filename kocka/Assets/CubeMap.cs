using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class CubeMap : MonoBehaviour
{
    private CubeState cubeState;

    public Transform up;
    public Transform down;
    public Transform left;
    public Transform right;
    public Transform front;
    public Transform back;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    public void Set()
    {
        cubeState = FindObjectOfType<CubeState>();

        UpdateMap(cubeState.front, front);
        UpdateMap(cubeState.back, back);
        UpdateMap(cubeState.left, left);
        UpdateMap(cubeState.right, right);
        UpdateMap(cubeState.up, up);
        UpdateMap(cubeState.down, down);
    }

  

    public void UpdateMap(List<GameObject> face, Transform side)
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
    }
}
