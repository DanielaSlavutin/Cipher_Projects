import React, {useState} from 'react';
import './style.css';

function App(){
    const[inputText, setInputText]=useState('');
    const [encryptedText, setEncryptedText]=useState('');

    const handleEncrypt=async()=>{
        try{
            const response=await fetch("http://127.0.0.1:3001/encrypt", {
                method: "POST",
                headers: {"Content-Type": "text/plain"},
                body: inputText,
            });

            const data=await response.text();
            console.log("Encrypted text from server: ", data);
            setEncryptedText(data);
        } catch(error){
            console.error("Error: ",error);
        }
    };

    return(
        <div className="app-container">
            <h1 className="title">Welcome to Caesar Cipher Machine!</h1>
            <label className="label">Please insert a text:</label>
            <input
                className="input"
                type="text"
                value={inputText}
                onChange={(e) => setInputText(e.target.value)}
            />
            <button className="button" onClick={handleEncrypt}>Send</button>

            <div className="output-container">
                <label className="label">The ecnrypted text:</label>
                <input className="output" type="text" value={encryptedText} readOnly />
            </div>
        </div>
    );
}

export default App;