using UnityEngine;
using System.Collections;

public class UIManager : MonoBehaviour {

    public GameManager GM;

    void Update()
    {
        ScanForKeyStroke();
    }
    void ScanForKeyStroke()
    {
        if (Input.GetKeyDown("escape")) GM.TogglePauseMenu();
    }
}
