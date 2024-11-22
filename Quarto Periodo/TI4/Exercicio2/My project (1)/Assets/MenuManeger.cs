using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class MenuManeger : MonoBehaviour
{
    [SerializeField] private string nomeLevelDeJogo;
    [SerializeField] private GameObject painelInicial;
    [SerializeField] private GameObject painelOpcoes;

    // Variável estática para definir se deve abrir as opções
    public static bool openConfig = false;

    // Método chamado ao clicar em "Jogar"
    public void Jogar()
    {
        SceneManager.LoadScene(nomeLevelDeJogo);
    }

    // Método para abrir o painel de opções
    public void AbrirOpcoes()
    {
        painelInicial.SetActive(false);
        painelOpcoes.SetActive(true);
    }

    // Método para fechar o painel de opções
    public void FecharOpções()
    {
        painelInicial.SetActive(true);
        painelOpcoes.SetActive(false);
    }

    void OnEnable()
    {
        SceneManager.sceneLoaded += OnSceneLoaded;
    }

    void OnDisable()
    {
        SceneManager.sceneLoaded -= OnSceneLoaded;
    }

    // Método chamado ao clicar em "Configurações"
    public void CallConfig()
    {
        openConfig = true; // Define que as opções devem ser abertas
        SceneManager.LoadScene("Menu");
    }

    // Método chamado ao clicar em "Menu"
    public void CallMenu()
    {
        openConfig = false; // Define que as opções não devem ser abertas
        SceneManager.LoadScene("Menu");
    }

    // Método que verifica quando uma cena é carregada
    void OnSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        if (scene.name == "Menu")
        {
            // Verifica se as opções devem ser abertas
            if (openConfig)
            {
                AbrirOpcoes();
            }
        }
    }

    // Método para sair do jogo
    public void SairDoJogo()
    {
        Debug.Log("Sair do Jogo");
        Application.Quit(); // Fecha o jogo
    }
}
