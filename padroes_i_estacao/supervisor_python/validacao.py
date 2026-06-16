def validar_leitura(leitura: dict) -> None:
    obrigatorios = {"tag", "valor", "unidade", "timestamp", "status"}
    faltantes = obrigatorios - set(leitura)

    if faltantes:
        raise ValueError(f"Campos ausentes: {sorted(faltantes)}")

    if not isinstance(leitura["tag"], str):
        raise TypeError("tag deve ser texto")

    if not isinstance(leitura["unidade"], str):
        raise TypeError("unidade deve ser texto")

    if not isinstance(leitura["timestamp"], str):
        raise TypeError("timestamp deve ser texto")

    if not isinstance(leitura["status"], str):
        raise TypeError("status deve ser texto")

    if leitura["status"] != "falha" and not isinstance(leitura["valor"], int | float):
        raise TypeError("valor deve ser numerico quando status nao e falha")
