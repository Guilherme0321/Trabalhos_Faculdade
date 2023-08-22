
public class Users {
	private int id;
	private String name;
	private String lastName;
	private String email;
	private String password;
	
	public Users() {
	}
	
	public Users(int id, String name, String lastName, String email, String password) {
		this.id = id;
		this.name = name;
		this.email = email;
		this.lastName = lastName;
		this.password = password;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) {
		this.lastName = lastName;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}
	
	@Override
	public String toString() {
		return "[ id: " + this.id + ", nome: " + this.name + ", ultimo_nome: " + this.lastName + ", email: " + this.email + ", senha: " + this.password;
	}

}
