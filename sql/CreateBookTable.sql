USE [BookInventory]
GO

/****** Object:  Table [dbo].[Books]    Script Date: 7/5/2021 9:19:09 PM ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[Books](
	[Id] [bigint] IDENTITY(1,1) NOT NULL,
	[Title] [nvarchar](20) NULL,
	[PublishDate] [datetime2](7) NULL,
	[ISBN] [nvarchar](36) NULL,
	[AuthorId] [bigint] NULL
) ON [PRIMARY]
GO
