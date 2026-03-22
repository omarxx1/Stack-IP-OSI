🧱 1. Architettura reale (IMPORTANTE)

 rispetta il modello OSI Model: (basic)

🔽 SEND (top → down)
Application
→ Session
→ Presentation
→ Transport
→ Network
→ DataLink
→ Physical

🔼 RECEIVE (bottom → up)
Physical
→ DataLink
→ Network
→ Transport
→ Session
→ Presentation
→ Application

👉 Ogni layer chiama SOLO quello sotto (send) o sopra (receive)




#### esecuzione progetto:
chmod +x build_and_run.sh
./build_and_run.sh