using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Coletor : MonoBehaviour
{
    public int pontos;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    private void OnControllerColliderHit(ControllerColliderHit hit)
    {
        if(hit.gameObject.CompareTag("coletavel"))
        {
            pontos += hit.gameObject.GetComponent<Item>().valor;
            Destroy(hit.gameObject);
        }
    }
}
