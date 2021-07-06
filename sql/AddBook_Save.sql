USE [BookInventory]
GO

/****** Object:  StoredProcedure [dbo].[InsertBook]    Script Date: 7/5/2021 9:21:20 PM ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE PROCEDURE [dbo].[InsertBook]
	-- Add the parameters for the stored procedure here
	@title nvarchar(20),
	@publishDate nvarchar(36),
	@isbn nvarchar(36),
	@authorFirstName nvarchar(36),
	@authorLastName nvarchar(36)
AS
BEGIN
	DECLARE
	@authorId bigint

	SELECT 
	@authorId = [Id] FROM [dbo].[Authors]
	WHERE [FirstName] = @authorFirstName 
	AND [LastName] = @authorLastName

	INSERT INTO [dbo].[Books](
		Title,
		PublishDate,
		ISBN,
		AuthorId
	)
	VALUES(
		@title,
		CONVERT(datetime2, @publishDate),
		@isbn,
		@authorId
	)
END
GO
