using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public float speed = 0.005f;
    public float rotationSpeed = 50.0f; // diminui a rotação para 50 para torná-la mais lenta

    void Update()
    {
        // Pegar as entradas do eixo
        float translation = Input.GetAxis("Vertical") * speed;
        float rotation = Input.GetAxis("Horizontal") * rotationSpeed * Time.deltaTime;

        // Movimentar e rotacionar o jogador
        transform.Translate(0, 0, translation);
        transform.Rotate(0, rotation, 0);
    }
}
