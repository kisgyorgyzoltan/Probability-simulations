using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class Spawner : MonoBehaviour
{
    public MersenneTwister random = new MersenneTwister();
    public List<GameObject> tuk = new List<GameObject>();
    public GameObject tuPrefab;
    private float spawnTime = 1f;
    [SerializeField] private float spawnDelay = 0.5f;
    [SerializeField] private MeshRenderer planeMeshRenderer;
    [SerializeField] private int maxtuk;

    // Update is called once per frame
    void Update()
    {

        // Spawn a new tuPrefab every spawnTime seconds
        spawnTime -= Time.deltaTime;
        if (spawnTime <= 0)
        {
            for (int i = 0; i < 10; i++)
            {
                Vector3 randompoz = new Vector3(random.NextSingle(planeMeshRenderer.bounds.min.x, planeMeshRenderer.bounds.max.x), 8, random.NextSingle(planeMeshRenderer.bounds.min.z, planeMeshRenderer.bounds.max.z));
                Quaternion rotation = new Quaternion(90, random.Next(0, 181), random.Next(0, 181), random.Next(0, 181));
                GameObject tu = Instantiate(tuPrefab, randompoz, rotation);
                tu.transform.SetParent(gameObject.transform);
                tuk.Add(tu);
            }
            spawnTime = spawnDelay;
        }
        if (tuk.Count > maxtuk)
        {
            foreach(GameObject tu in tuk)
            {
                Destroy(tu);
            }
            tuk.Clear();
        }
    }
}