package modelo;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Pessoa {
		
	private String cpf;
	private String nome;
	private String nacionalidade;
	private String genero;
	private LocalDateTime dataNascionalidade;
	private String telefone;
	private String estadoCivil;
	
	public Pessoa(String cpf, String nome, String nacionalidade, String genero, LocalDateTime dataNascimento, String telefone, String estado_civil) {
		this.setCpf(cpf);
		this.setNome(nome);
		this.setNacionalidade(nacionalidade);
		this.setGenero(genero);
		this.setDataNascionalidade(dataNascimento);
		this.setTelefone(telefone);
		this.setEstadoCivil(estado_civil);
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		if(cpf.length() >= 11) {			
			this.cpf = cpf;
		}
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getNacionalidade() {
		return nacionalidade;
	}

	public void setNacionalidade(String nacionalidade) {
		this.nacionalidade = nacionalidade;
	}

	public String getGenero() {
		return genero;
	}

	public void setGenero(String genero) {
		this.genero = genero;
	}

	public LocalDateTime getDataNascionalidade() {
		return dataNascionalidade;
	}

	public void setDataNascionalidade(LocalDateTime dataNascionalidade) {
		if(LocalDateTime.now().compareTo(dataNascionalidade) >= 0) {			
			this.dataNascionalidade = dataNascionalidade;
		}
	}

	public String getTelefone() {
		return telefone;
	}

	public void setTelefone(String telefone) {
		if(telefone == null || telefone.length() >= 13) {			
			this.telefone = telefone;
		}
	}

	public String getEstadoCivil() {
		return estadoCivil;
	}

	public void setEstadoCivil(String estadoCivil) {
		this.estadoCivil = estadoCivil;
	}
	
	@Override
	public String toString() {
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd'T'HH:mm:ss");
		return getNome() + "|" + getNacionalidade() + "|" + getGenero() + "|" + getDataNascionalidade().format(formatter) + "|" + getTelefone() + "|" + getEstadoCivil();
	}
	
}
