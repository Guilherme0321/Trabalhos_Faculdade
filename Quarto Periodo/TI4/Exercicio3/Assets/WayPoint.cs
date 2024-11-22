using System.Collections;
using System.Collections.Generic; 
using UnityEngine;
using UnityEngine.AI;

public class WayPoint : MonoBehaviour
{
    public Transform[] waypoint;
    private Vector3 origem, destino;
    float inicio, comprimento;
    int i = 1;

    // Start is called before the first frame update 
    void Start()
    {
        origem = waypoint[0].position;
        destino = waypoint[1].position;
        inicio = Time.time;  // Corrigido
        comprimento = Vector3.Distance(origem, destino);
    }

    // Update is called once per frame
    void Update()
    {
        float tempo = Time.time - inicio;  // Corrigido
        float velocidade = (tempo / comprimento) * 3;
        this.transform.position = Vector3.Lerp(origem, destino, velocidade);

        if (Vector3.Distance(this.transform.position, destino) == 0)
        {
            i++;
            origem = destino;
            if (i % waypoint.Length == 0)
            {
                i = 0;
            }
            destino = waypoint[i].position;

            comprimento = Vector3.Distance(origem, destino);
            inicio = Time.time;  // Corrigido
        }
    }
}
